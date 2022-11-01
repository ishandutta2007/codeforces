#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    set<int> s;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        if(arr[i]%2==1) s.insert(arr[i]+1);
        else s.insert(arr[i]-1);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==(*it))
            {
                if((*it)%2==1)
                {
                    arr[i]++;
                }
                else arr[i]--;
            }
        }
    }
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}