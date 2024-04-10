#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
vi t;
vi fail;
bool work(int i, int j){
    int x = t[j];
    int y = t[i];
    bool isTrue = true;
    if(i%2 == 1){
        if(!(x< t[i+1]&& x<t[i-1])){
            isTrue = false;
        }
    }
    else{
        if(!(x> t[i+1]&& x>t[i-1])){
            isTrue = false;
        }
    }
    if(j%2 == 1){
        if(!(y< t[j+1]&& y<t[j-1])){
            isTrue = false;
        }
    }
    else{
        if(!(y> t[j+1]&& y>t[j-1])){
            isTrue = false;
        }
    }
    return isTrue;
}
int main(){
    fast_io();
    int n;
    cin >> n;
    t.eb(1e6);
    f0r(i, n){
        int d;
        cin >> d;
        t.eb(d);
    }
    if(n%2 == 0){
        t.eb(-1e6);
    }
    else{
        t.eb(1e6);
    }
    f1r(i, 1, n+1){
        if(i%2 == 1){
            if(t[i] >=t[i+1]){
                fail.eb(i);
            }
        }
        else{
            if(t[i]<= t[i+1]){
                fail.eb(i);
            }
        }
    }
    if(fail.size()>4){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    if(fail.size() == 1){
        int x = fail[0];
        f1r(i,1,  n+1){
            if(x!= i && work(x, i)&& x!= i){
                ans += 1;
               // cout << x << " " << i << endl;
            }
        }
        f1r(i,1,  n+1){
            if(x+1!= i && work(x+1, i)&& i != x+1){
                ans += 1;
                //cout << x+1 << " " << i << endl;
            }
        }
        if(x%2 == 1){
            if(t[x-1] >t[x+1] && t[x+1]< t[x]&&t[x] >t[x+2]){
                ans += 1;
            }
        }
        else{
            if(t[x-1] <t[x+1] && t[x+1]> t[x]&&t[x] <t[x+2]){
                ans += 1;
            }
        }
        cout << ans;
        return 0;
    }
    else{
        vector<int> pos;
        for(int x:fail){
            pos.eb(x);
            pos.eb(x+1);
        }
        set<int> s;
        int size = pos.size();
        for( int i = 0; i < size; ++i ) s.insert( pos[i] );
        pos.assign( s.begin(), s.end() );
        for(int a: pos){
            for(int b: pos){
                if(a!= b){
                    int temp = t[a];
                    t[a] = t[b];
                    t[b] = temp;
                    bool isTrue = true;
                    f1r(i, 1, n+1){
                        if(i%2 == 1){
                            if(t[i] >=t[i+1]){
                                isTrue = false;
                                break;
                            }
                        }
                        else{
                            if(t[i]<= t[i+1]){
                                isTrue = false;
                                break;
                            }
                        }
                    }
                    if(isTrue){
                        ans += 1;
                    }
                    temp = t[a];
                    t[a] = t[b];
                    t[b] = temp;
                }
            }
        }
        
        ans = ans /2;
        if(fail.size() == 2){
            if(fail[0] + 1 == fail[1]){
                int x = fail[1];
                f1r(i,1,  n+1){
                    if(x!= i && work(x, i)&& x+1!= i&& x-1!=i){
                        ans += 1;
                       // cout << x << " " << i << endl;
                    }
                }
            }
        }
        cout << ans<< endl;
    }
    return 0;
}