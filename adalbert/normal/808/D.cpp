#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define int long long
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=5e5;
int a[arr];
///---program start---///
main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    multiset<int> left,right;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=a[i];
        right.insert(a[i]);
    }
    int sum_=0;
    for (int i=1;i<n;i++)
    {
        sum_+=a[i];
        if (sum_==sum-sum_)
        {
            cout<<"YES";
            return(0);
        }
        left.insert(a[i]);
        //cout<<sum_<<' '<<sum-sum_<<'\n';
        right.erase(right.find(a[i]));
        if (left.count((sum_-(sum-sum_))/2) && (sum_-(sum-sum_))%2==0)
        {
            cout<<"YES";
            return(0);
        }
        if (right.count((-sum_+(sum-sum_))/2) && (-sum_+(sum-sum_))%2==0)
        {
            cout<<"YES";
            return(0);
        }
    }
    for (int i=1;i<=n;i++)
        if (a[i]==sum/2 && sum%2==0)
    {
        cout<<"YES";
        return(0);
    }
    cout<<"NO";

}