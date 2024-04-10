#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

map<char,int> mp;
void q1()
{
    string s;
    int n,m;
    cin >> n >> m >> s;

    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }

    bool b=true;
    for(int i=0;i<s.size();i++)
    {
        if(mp[s[i]]>m)
        {
            b=false;
        }
    }

    cout << (b?"YES":"NO");
}

void q2()
{
    string y[]={"","one","two","three","four","five","six","seven","eight","nine"};
    string yd[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string d[]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    int n;
    cin >> n;
    if(n==0)
    {
        cout << "zero";
    }
    else if(n/10==1)
    {
        cout << yd[n%10];
    }
    else if(n/10==0)
    {
        cout << y[n];
    }
    else
    {
        cout << d[n/10] << (n%10!=0?"-":"") << y[n%10];
    }
}

void q3()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    Sort(a);
    int ans=n-2 , p=0;

    while(a[p] == a[p+1])
    {
        p++;
        ans--;
    }
    p=n-1;
    while(a[p] == a[p-1])
    {
        p--;
        ans--;
    }

    cout << max(0,ans) << endl;
}

void q4()
{
    int n=5 , sum=0 , m=0;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    Sort(a);
    for(int i=0;i<n;i++)
    {
        int s=0;
        if(i!=n)
        {
            if(a[i]==a[i+1])
            {
                s=a[i]+a[i+1];
            }
        }
        if(i<n-1)
        {
            if(a[i]==a[i+2])
            {
                s+=a[i+2];
            }
        }
        m=max(m,s);
    }

    cout << sum-m << endl;
}

int main()
{
    q2();
    return 0;
}