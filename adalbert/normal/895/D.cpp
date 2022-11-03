#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); coutcout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=2e6;

int fact[arr],rfact[arr],cnt[2000];
const int md=1e9+7;

int dill(int a, int b)
{
    a*=rfact[b];
    a%=md;
    a*=fact[b-1];
    a%=md;
    return(a);
}

int pow(int u, int step)
{
    if (step==0)
        return(1);
    if (step%2)
    {
        return(pow(u,step-1)*u%md);
    } else
    {
        int now=pow(u,step/2);
        return(now*now%md);
    }
}

int mno(int a, int b)
{
    a*=b;
    a%=md;
    return(a);
}

signed main()
{
    string st1,st2;
    cin>>st1>>st2;

    int all=1;
    fact[1]=1;
    for (int i=2;i<arr;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=md;
    }

    rfact[arr-1]=pow(fact[arr-1],md-2);

    for (int i=arr-2;i>=1;i--)
    {
        rfact[i]=rfact[i+1]*(i+1);
        rfact[i]%=md;
    }
    rfact[0]=1;


    for (int i=0;i<st1.size();i++)
    {
        cnt[st1[i]]++;
    }

    all=fact[st1.size()];
    for (int i=0;i<=500;i++)
        if (cnt[i]!=0)
        {
            all*=rfact[cnt[i]];
            all%=md;
        }


    int ans=0;
    for (int i=0;i<st1.size();i++)
    {
        for (int now='a';now<='z';now++)
            if (now<st1[i] && cnt[now]!=0)
            {
                int nw=dill(all,st1.size()-i);
                nw=mno(nw,cnt[now]);
                ans+=nw;
                ans%=md;
            }
        all=dill(all,st1.size()-i);
        all=mno(all,cnt[st1[i]]);
        cnt[st1[i]]--;
    }
    ans++;
    ans%=md;


    for (int i=0;i<st1.size();i++)
    {
        cnt[st1[i]]++;
    }

    all=fact[st1.size()];
    for (int i=0;i<=500;i++)
        if (cnt[i]!=0)
        {
            all*=rfact[cnt[i]];
            all%=md;
        }



    for (int i=0;i<st1.size();i++)
    {
        for (int now='a';now<='z';now++)
            if (now>st2[i] && cnt[now]!=0)
            {
                int nw=dill(all,st1.size()-i);
                nw=mno(nw,cnt[now]);
                ans+=nw;
                ans%=md;
            }

        all=dill(all,st1.size()-i);
        all=mno(all,cnt[st2[i]]);
        cnt[st2[i]]--;
        if (cnt[st2[i]]<0)
            break;
        if (i==st1.size()-1)
        {
            ans++;
            ans%=md;
        }

    }

    for (int i=0;i<=500;i++)
        cnt[i]=0;
    for (int i=0;i<st1.size();i++)
        cnt[st1[i]]++;

    all=fact[st1.size()];

    for (int i=0;i<=500;i++)
        if (cnt[i]!=0)
        {
            all*=rfact[cnt[i]];
            all%=md;
        }

    cout<<(all-ans+md)%md;
}

/*
1
0.1 0.2 0.3
1.0 0.5 0.3
1.0 0.0 0.2
*/