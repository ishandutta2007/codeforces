#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    bool m[n];
    multiset<int> s;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        m[i]=0;
        s.insert(arr[i]);
    }
    int cnt=0;
    int ans=0;
    for(multiset<int>::reverse_iterator it=s.rbegin();it!=s.rend();it++)
    {
        if(cnt==k) break;
        ans+=(*it);
        for(int i=0;i<n;i++)
        {
            if(!m[i] && arr[i]==(*it))
            {
                m[i]=1;
                break;
            }
        }
        cnt++;
    }
    cout << ans << endl;
    int part=1;
    int idx=0;
    while(part<k)
    {
        int len=0;
        for(;;idx++)
        {
            if(!m[idx])
            {
                len++;
                continue;
            }
            len++;
            cout << len << " ";
            break;
        }
        idx++;
        part++;
    }
    cout << n-idx << endl;


    return 0;
}