#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> degs;

int main()
{
    int k = 1;
    while (k<10000000)
    {
        degs.push_back(k);
        k*=2;
    }
    
    int n;
    cin>>n;
    if (n==3)
    {
        cout<<1<<' '<<1<<' '<<3;
        return 0;
    }
    vector<int> ans;
    int n1 = n;
    while (n)
    {
        ans.push_back(n);
        n/=2;
    }
    vector<int> answer;
    int idx = 0;
    int current = ans.size();
    current--;
    while (current>=0)
    {
        while (idx<ans[current])
        {
            answer.push_back(degs[current]);
            idx++;
        }
        current--;
    }
    if (n1>=4)
    {
        if (answer[0]==2*answer[1]&&answer[1]==answer[2]&&answer[2]!=answer[3]) answer[0] = answer[1]*3;
    }
    for (int i = n1-1; i>=0; i--) cout<<answer[i]<<' ';
}