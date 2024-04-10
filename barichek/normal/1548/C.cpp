//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 3e6+10, inf = 1000111222;
const int md=1e9+7;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int f[max_n];
int rf[max_n];

int C(int n,int k)
{
    if (k>n){
        return 0;
    }
    return 1ll*f[n]*rf[n-k]%md*rf[k]%md;
}

int ans[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    f[0]=1;
    for (int i=1;i<max_n;i++){
        f[i]=1ll*f[i-1]*i%md;
    }
    rf[max_n-1]=inv(f[max_n-1]);
    for (int i=max_n-2;i>=0;i--){
        rf[i]=1ll*rf[i+1]*(i+1)%md;
    }

    int a=0;
    int b=0;
    int c=0;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        inc(a,3*i);
        inc(b,3*i-1);
        inc(c,3*i-2);
    }
    int inv3 = inv(3);
    for (int x=1;;){
        ans[x]=a;



        x++;
        if (x==3*n+1){
            break;
        }

        /// new_a = b + new_b
        /// new_b = c + new_c
        /// new_c = (a-C(3*n,x-1)) + (new_a-C(3*n,x))

        /// new_a = b + (c + new_c)
        /// new_a = b + (c + (a-C(3*n,x-1)) + (new_a-C(3*n,x)))


        /// new_a + new_b + new_c = C(3*n+1,x+1)
        /// b + new_b + new_b + (a-C(3*n,x-1)) + (b + new_b -C(3*n,x)) = C(3*n+1,x+1)

//        int to_be_zero=b+c+a-C(3*n,x-1)-C(3*n,x);
//        cout<<"to_be_zero :: "<<to_be_zero<<"\n";
//        cout<<"to_be_zero 2 :: "<<a+b+c-C(3*n+1,x)<<"\n";

        int C_3n_x = C(3*n,x);
        int C_3n_xm1 = C(3*n,x-1);

        ll new_b = 1ll*C(3*n+1,x+1) - 1ll*(a-C_3n_xm1) - 1ll*(b + -C_3n_x) - 1ll*b;
        while (new_b<0){
            new_b+=md;
        }
        while (new_b>=md){
            new_b-=md;
        }
        new_b=new_b*inv3%md;

        ll new_a=b+new_b;
        if (new_a>=md){
            new_a-=md;
        }

        ll new_c = 1ll*(a-C_3n_xm1) + 1ll*(new_a-C_3n_x);
        while (new_c<0){
            new_c+=md;
        }
        while (new_c>=md){
            new_c-=md;
        }

        a=new_a;
        b=new_b;
        c=new_c;

//        a=0;
//        b=0;
//        c=0;
//        for (int i=1;i<=n;i++){
//            inc(a,C(3*i,x));
//            inc(b,C(3*i-1,x));
//            inc(c,C(3*i-2,x));
//        }
    }

    int q;
    scanf("%d",&q);
    while (q--){
        int x;
        scanf("%d",&x);
        cout<<ans[x]<<"\n";
    }
}