#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int cnt[101];
    for(int i=0;i<=100;i++) cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int one=0,split=0;
    for(int i=1;i<=100;i++)
    {
        if(cnt[i]==1) one++;
        if(cnt[i]>2) split++;
    }
    if((one&1)==0)
    {
        cout << "YES" << endl;
        int a=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[arr[i]]==1)
            {
                if(a<(one/2)) cout << 'A';
                else cout << 'B';
                a++;
            }
            else cout << 'A';
        }
    }
    else if(split)
    {
        int idx;
        for(int i=1;i<=100;i++)
        {
            if(cnt[i]>2)
            {
                idx=i;
                break;
            }
        }
        cout << "YES" << endl;
        int a=0;
        bool notDone=1;
        for(int i=0;i<n;i++)
        {
            if(cnt[arr[i]]==1)
            {
                if(a<((one+1)/2)) cout << 'A';
                else cout << 'B';
                a++;
            }
            else if(arr[i]==idx)
            {
                if(notDone)
                {
                    cout << 'B';
                    notDone=0;
                }
                else cout << 'A';
            }
            else cout << 'A';
        }
    }
    else cout << "NO" << endl;
    return 0;
}