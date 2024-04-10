#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[26];
    for(int i=0;i<26;i++) num[i]=0;
    char arr[n+1];
    cin >> arr;
    if(n==1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        num[arr[i]-97]++;
    }
    bool good=0;
    for(int i=0;i<26;i++)
    {
        if(num[i]>1)
        {
            good=1;
            break;
        }
    }
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}