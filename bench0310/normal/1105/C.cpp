#include <iostream>

using namespace std;

const int N=200000;
const long long MOD=1000000007;
long long mem[N][3];
long long a[3];
int n,l,r;

long long exe(int idx,int mod)
{
    if(idx==n-1) return a[(3-mod)%3];
    if(mem[idx][mod]!=-1) return mem[idx][mod];
    long long cnt=0;
    for(int i=0;i<3;i++)
    {
        cnt+=a[i]*exe(idx+1,(mod+i)%3);
        if(cnt>=MOD) cnt%=MOD;
    }
    mem[idx][mod]=cnt;
    return cnt;
}

int main()
{
    for(int o=0;o<N;o++) for(int i=0;i<3;i++) mem[o][i]=-1;
    cin >> n >> l >> r;
    a[0]=(r/3)-((l-1)/3);
    a[1]=((r+2)/3)-((l+1)/3);
    a[2]=((r+1)/3)-(l/3);
    cout << exe(0,0) << endl;
    return 0;
}