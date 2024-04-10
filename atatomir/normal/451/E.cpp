#include <iostream>
#include <fstream>

#define mod 1000000007

using namespace std;

long n,i;
long long f[25],rez=0,s;

//ifstream fin("test.in");

inline unsigned long long up(long long a,long long b){
    unsigned long long rez=1;
    while(b > 0){
        if(b & 1) rez = (rez*a)% mod;
        a = (a*a)% mod;
        b >>= 1;
    }
    return rez;
}

inline long long myComb(long long n,long long k){
    k--; n+= k;
    long long result=1;
    long long i,c;

    for(i=n-k+1;i<=n;i++) result = (result*(i% mod))% mod;

    c=1;
    for(i=2;i<=k;i++) c = (c*i)% mod;
    c = up(c,mod-2);

    result = (result*c)% mod;

    return result;
}

void Recurs(int pas,int sel,long long sum){
    //cout << pas << ' ' << sel << ' ' << sum << '\n';

    if(sum < 0) return;

    if(pas > n) {
        if(sel % 2 == 0)
            rez = (myComb(sum,n) + rez)% mod;
        else{
            rez= -myComb(sum,n) + rez;
            while(rez < 0) rez+= mod;
            rez %= mod;
        }
        return;
    }

    Recurs(pas+1,sel,sum);
    Recurs(pas+1,sel+1,sum-f[pas]-1);
}

int main()
{
    cin >> n >> s;
    for(i=1;i<=n;i++) cin >> f[i];

    Recurs(1,0,s);

    cout << rez << '\n';

    return 0;
}