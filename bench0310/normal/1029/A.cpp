#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    char arr[n+1];
    cin >> arr;
    int m=0;
    for(int i=1;i<n;i++)
    {
        bool good=1;
        for(int b=i;b<n;b++)
        {
            if(arr[b]!=arr[b-i])
            {
                good=0;
                break;
            }
        }
        if(good)
        {
            m=n-i;
            break;
        }
    }
    if(m==0)
    {
        int space=(k*n)+1;
        char ans[space];
        strcpy(ans,arr);
        k--;
        while(k)
        {
            strcat(ans,arr);
            k--;
        }
        cout << ans;
    }
    else
    {
        char str[n-m+1];
        int cur=0;
        for(int i=m;i<n;i++)
        {
            str[cur]=arr[i];
            cur++;
        }
        str[cur]='\0';
        int space=n+(k-1)*(n-m)+1;
        char ans[space];
        strcpy(ans,arr);
        k--;
        while(k)
        {
            strcat(ans,str);
            k--;
        }
        cout << ans;
    }
    cout << endl;
    return 0;
}