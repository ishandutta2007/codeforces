#include <bits/stdc++.h>
using namespace std;
const int N=5000;
vector<int> ans(N,0);
int a[N];

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i], a[i]--;
    for(int i=0; i<n; i++)
    {
        vector<int> c(n,0);
        int dc=0;
        for(int j=i; j<n; j++)
        {
            c[a[j]]++;
            if(c[a[j]]>c[dc]||(c[a[j]]==c[dc]&&a[j]<dc))
                dc=a[j];
            ans[dc]++;
        }
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<' ';
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
vector<bool> a(90,false);

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin>>n;
    for(int i=0,t; i<n; i++)
        cin>>t, a[t-1]=true;

    int s=0;
    for(int i=0; i<15; i++) s+=a[i];

    int ans=15;
    while(ans<90&&s)
    {
        s+=a[ans]-a[ans-15];
        ans++;
    }

    cout<<ans;
    return 0;
}
*/