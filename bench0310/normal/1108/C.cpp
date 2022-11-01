#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    char arr[3]={'B','G','R'};
    string best;
    int val=1000000000;
    do
    {
        string temp;
        int idx=0;
        for(int i=0;i<n;i++)
        {
            temp+=arr[idx];
            idx=(idx+1)%3;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=temp[i]) cnt++;
        }
        if(cnt<val)
        {
            val=cnt;
            best=temp;
        }
    } while(next_permutation(arr,arr+3));
    cout << val << endl;
    cout << best << endl;
    return 0;
}