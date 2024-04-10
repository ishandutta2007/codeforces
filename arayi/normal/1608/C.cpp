#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cout.tie(0);
#define str string
#define ad push_back
#define MP make_pair
#define fr first
#define sc second
#define lli long long int
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e6 + 20;


int t, n;
pair<int, int> a[N], b[N];
int ind[N], pat[N], ind1[N];
int mn[N], mn1[N];
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i].fr;
            a[i].sc=i;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i].fr;
            b[i].sc=i;
        }
        sort(a,a+n);
        sort(b,b+n);
        for (int i = 0; i < n; i++)
            ind[b[i].sc]=i, ind1[a[i].sc]=i;
        
        int mx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            mn[i]=ind[a[i].sc];
            mn1[i]=ind1[b[i].sc];
            if(i!=n-1) mn[i]=min(mn[i], mn[i+1]), mn1[i]=min(mn1[i], mn1[i+1]);
        }
        int i1 = n-1, i2=n-1;
        while (i1!=mn[i2]||i2!=mn1[i1])
        {
            i1=mn[i2];
            i2=mn1[i1];
        }
        for (int i = 0; i < n; i++) pat[i]=0;
        for (int i = 0; i < n; i++)
        {
            if(i>=i1) pat[b[i].sc]=1;
            if(i>=i2) pat[a[i].sc]=1;
        }
        for (int i = 0; i < n; i++) cout<<pat[i];
        cout<<endl;
    }
    
    return 0;
}