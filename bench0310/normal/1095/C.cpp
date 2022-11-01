#include <bits/stdc++.h>

using namespace std;

vector<int> exe(int p,int k)
{
    vector<int> v;
    if(k==1)
    {
        v.push_back(p);
        return v;
    }
    v=exe(p/2,k/2);
    vector<int> temp=exe(p/2,k-k/2);
    v.insert(v.end(),temp.begin(),temp.end());
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    string b=bitset<32>(n).to_string();
    if(k>=__builtin_popcount(n)&&k<=n)
    {
        cout << "YES" << endl;
        int l=__builtin_popcount(n);
        for(int i=31;i>=0;i--)
        {
            //31-i
            if(b[i]=='1')
            {
                int sum=min(k-l+1,(1<<(31-i)));
                vector<int> v=exe(1<<(31-i),sum);
                for(int i=0;i<(int)v.size();i++) cout << v[i] << " ";
                l--;
                k-=sum;
            }
        }
    }
    else cout << "NO" << endl;
    return 0;
}