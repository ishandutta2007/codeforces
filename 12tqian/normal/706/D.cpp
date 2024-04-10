#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}

const int PAD = 30;
string pad(ll x){
    string ans = "";
    while(x> 0){
        if(x%2 == 0){
            ans = "0" + ans;
        }
        else{
            ans = "1" + ans;
        }
        x = (x>> 1);
    }
    int siz = ans.size();
    for(int i = 0; i<PAD - siz; i++){
        ans  = "0" + ans;
    }
    return ans;
}
struct Trie {

    // isEndOfWord is true if the node
    // represents end of a word
    bool isEndOfWord;
    int isLeaf;

    /* nodes store a map to child node */
    unordered_map<char, Trie*> map;
};
/*function to make a new trie*/
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isEndOfWord = false;
    node->isLeaf = 0;
    return node;
}

/*function to insert in trie*/
void insert(Trie*& root, const string& str)
{
    if (root == nullptr){
        root = getNewTrieNode();
    }
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        temp->isLeaf += 1;
        //cout << temp->isLeaf << "  asdfasdF "  << i << endl;
        /* make a new node if there is no path */
        if (temp->map.find(x) == temp->map.end()||temp->map[x] ==nullptr){
            temp->map[x] = getNewTrieNode();
        }
        temp = temp->map[x];
    }
    if(temp!= nullptr){
        temp->isLeaf += 1;
        temp->isEndOfWord = true;
    }
}

/*function to search in trie*/
ll search(Trie* root, const string& str){
    Trie* temp = root;
    ll ans = 0;
    ll shift = 29;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '0'){
            if (temp->map['1'] == nullptr|| (temp->map['1'])->isLeaf == 0){
                temp = temp->map['0'];
               // cout << 0 << endl;
            }
            else{
               // cout<< i << " hi" << endl;
                temp = temp->map['1'];
                ans += (1<< (shift - i));
               // cout << 1 << endl;
            }
        }
        else{
            if (temp->map['0'] == nullptr|| (temp->map['0'])->isLeaf == 0){
                temp = temp->map['1'];
               // cout << 1 << endl;
            }
            else{
                 //   cout<< i << " hi" << endl;
                temp = temp->map['0'];
                ans += (1<< (shift - i));
             //   cout << 0 << endl;
            }
        }
    }
    return ans;
}

void del(Trie*& root, const string& str){
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        temp->isLeaf -= 1;
        temp = temp->map[x];
       // cout << i << endl;
    }
    if(temp != nullptr){
        temp->isLeaf -=1;
    }

}
vector<char> v1;
vector<ll> v2;
int main(){
    int q;
    cin >> q;
    f0r(i, q){
        char c;
        cin >> c;
        ll x;
        cin >> x;
        v1.eb(c);
        v2.eb(x);
    }
    Trie* root = nullptr;


    insert(root, pad(0));
    insert(root, pad(0));
    insert(root, pad(0));
    f0r(i, q){
        char c = v1[i];
        int x = v2[i];
        string s = pad(x);
       // cout << s << " astring " << s.size() << endl;
        if(c == '+'){
          //  cout << "asdf" << endl;
            insert(root, s);
           // cout << "asdfasD" << endl;
          // cout << searching(root, s) << " sear" << endl;
        }
        else if(c == '-'){
               // cout << "hi" << endl;
            del(root, s);
        }
        else{
            cout << search(root, s) << endl;
        }

    }
    return 0;
}