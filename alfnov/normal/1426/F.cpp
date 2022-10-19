#include<bits/stdc++.h>
#define mod 1000000007ll
using namespace std;
char s[200005];
int q1[200005][4],q2[200005][4],pu[200005];
int ys(char c)
{
    if(c=='a')return 0;
    if(c=='b')return 1;
    if(c=='c')return 2;
    if(c=='?')return 3;
}
int powdv(int x,int y)
{
    if(y<0)return 0;
    int ans=1;
    while(y)
    {
        if(y&1)ans=(1ll*ans*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return ans;
}
int main()
{
	int ttt;
	cin>>ttt;
    scanf("%s",s);
    int n=strlen(s),q=0;
    for(int i=1;i<=n;i++)pu[i]=ys(s[i-1]),q+=(pu[i]==3);
    for(int i=2;i<=n;i++)
    {
        q1[i][0]=q1[i-1][0];
        q1[i][1]=q1[i-1][1];
        q1[i][2]=q1[i-1][2];
        q1[i][3]=q1[i-1][3];
        q1[i][pu[i-1]]++;
    }
    for(int i=n-1;i>=1;i--)
    {
        q2[i][0]=q2[i+1][0];
        q2[i][1]=q2[i+1][1];
        q2[i][2]=q2[i+1][2];
        q2[i][3]=q2[i+1][3];
        q2[i][pu[i+1]]++;
    }
    long long ans1=0;
    for(int i=1;i<=n;i++)if(pu[i]==1)ans1+=1ll*q1[i][0]*q2[i][2]%mod;
    ans1%=mod;
    ans1*=powdv(3,q);
    long long ans2=0;
    for(int i=1;i<=n;i++)if(pu[i]==3)ans2+=1ll*q1[i][0]*q2[i][3]%mod;
    for(int i=1;i<=n;i++)if(pu[i]==1)ans2+=1ll*q1[i][3]*q2[i][3]%mod;
    for(int i=1;i<=n;i++)if(pu[i]==3)ans2+=1ll*q1[i][3]*q2[i][2]%mod;
    ans2%=mod;
    ans2*=powdv(3,q-2);
    long long ans3=0;
    for(int i=1;i<=n;i++)if(pu[i]==1)ans3+=1ll*q1[i][0]*q2[i][3]%mod;
    for(int i=1;i<=n;i++)if(pu[i]==1)ans3+=1ll*q1[i][3]*q2[i][2]%mod;
    for(int i=1;i<=n;i++)if(pu[i]==3)ans3+=1ll*q1[i][0]*q2[i][2]%mod;
    ans3%=mod;
    ans3*=powdv(3,q-1);
    long long ans4=0;
    for(int i=1;i<=n;i++)if(pu[i]==3)ans4+=1ll*q1[i][3]*q2[i][3]%mod;
    ans4%=mod;
    ans4*=powdv(3,q-3);
    cout<<(ans1+ans2+ans3+ans4)%mod<<endl;
    return 0;
}