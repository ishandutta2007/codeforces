#include<bits/stdc++.h>
using namespace std;

bool issquare(long long k)
{
    long long t = sqrt(k);
    return (t*t==k);
}

void f(long long k)
{
    if (k==0) cout<<1<<' '<<1<<endl;
    else if (k%4==2) cout<<-1<<endl;
    else
    {
        bool can = false;
        int a = 1;
        while ((!can)&&(a<70000))
        {
            if (!issquare(k+a*a)) a++;
            else 
            {
                int n = sqrt(k+a*a);
                int m = n/a;
                int t = n%a;
                if (t>=m) a++;
                else {cout<<n<<' '<<m<<endl; can = true;}
            }
        }
        if (!can) cout<<-1<<endl;
        
    }
}

int main()
{
int t;
cin>>t;
for (int i = 0; i<t; i++)
{
    long long k;
    cin>>k;
    f(k);
}
}