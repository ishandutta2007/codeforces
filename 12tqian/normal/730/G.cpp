#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

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
set<int> ed;
map<int, int> m;
set<int, greater<int>> st;
set<int> st1;
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        int s, d;
        cin >> s >> d;
        if(i == 0){
            cout << s << " " << s +d-1 << endl;
            ed.insert(s+d-1);
            st.insert(s);
            st1.insert(s);
            m[s] = s+d-1;
        }
        else{
            int first = *st1.begin();
            bool isTrue = false;
            set<int>::iterator it2 = st.ub(s);
            int temp = *it2;
            set<int>::iterator it3 = st.ub(s);
            if(*st.lb(s) != s){
                it2 = st1.ub(s);
                //cout << temp << " asdf " << *it2 <<" " << *st1.end()<< endl;
                if((m[temp]<s || (it3 == st.end())) && (*it2>s+d-1 || (it2 == st1.end()))){
                    cout << s << " " << s +d-1 << endl;
                    ed.insert(s+d-1);
                    st.insert(s);
                    st1.insert(s);
                    m[s] = s+d-1;
                    continue;
                }
            }

            if(first>d){
                cout << 1 << " " << d << endl;
                ed.insert(d);
                st.insert(1);
                st1.insert(1);
                m[1] = d;
                continue;
            }
            for(auto it: ed){
                int cur = it;
                set<int>::iterator it2 = st.ub(cur);
                set<int>::iterator it3 = st.ub(cur);
                int prev = *it2;
                it2 = st1.ub(cur);
               // cout << prev << " " << *it3 << endl;
                if(*st.lb(s) != cur && (m[prev] < cur+1||it3 == st.end())&& (it2 == st1.end()||cur + d-1+1 < *it2)){
                    cout << cur +1<< " " << cur +d-1  +1<< endl;
                    ed.insert(cur+d);
                    st.insert(cur+1);
                    st1.insert(cur+1);
                    m[cur+1] = cur+d;
                    isTrue = true;
                    break;
                }
            }
            if(!isTrue){
                int last = *ed.rbegin();
                cout << last + 1 << " " << last +1 +d-1 << endl;
                ed.insert(last +d);
                st.insert(last+1);
                st1.insert(last+1);
                m[last+1] = last+d;
            }
        }

    }
    return 0;
}