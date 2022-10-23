#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;
ll n,p[N],vt[N],bit[N],ans[N];

void add(int x)
{
    for (int i=x;i<=n;i+=i&-i) bit[i]++;
}

ll get(int x)
{
    ll res=0;
    for (int i=x;i;i-=i&-i) res+=bit[i];
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],vt[p[i]]=i;
    for (int i=1;i<=n;i++)
    {
        ans[i]=get(n-vt[i]+1)+ans[i-1];
        add(n-vt[i]+1);
    }
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    ll s1=0,s2=0;
    for (int i=1;i<=n;i++)
    {
        if (max_heap.empty() || max_heap.top()>=vt[i]) s1+=vt[i],max_heap.push(vt[i]);
        else s2+=vt[i],min_heap.push(vt[i]);
        if (max_heap.size()>min_heap.size()+1)
        {
            s1-=max_heap.top();
            s2+=max_heap.top();
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (min_heap.size()>max_heap.size())
        {
            s1+=min_heap.top();
            s2-=min_heap.top();
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        ll siz1=max_heap.size(),siz2=min_heap.size();
        ll d1=(ll)max_heap.top()*siz1-s1-siz1*(siz1-1)/2;
        ll d2=s2-(ll)max_heap.top()*siz2-siz2*(siz2+1)/2;
        cout<<ans[i]+d1+d2<<" ";
    }
    return 0;
}