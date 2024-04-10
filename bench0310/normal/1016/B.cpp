#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int ls,lt,q;
    cin >> ls >> lt >> q;
    char s[ls+1];
    cin >> s;
    char t[lt+1];
    cin >> t;
    int arr[q][2];
    for(int i=0;i<q;i++) cin >> arr[i][0] >> arr[i][1];
    if(lt>ls)
    {
        for(int i=0;i<q;i++) cout << 0 << endl;
        return 0;
    }
    char str[ls-lt+1][lt+1];
    for(int i=0;i<ls-lt+1;i++)
    {
        for(int a=0;a<lt;a++)
        {
            str[i][a]=s[i+a];
        }
        str[i][lt]='\0';
    }
    int occ[ls-lt+1];
    for(int i=0;i<ls-lt+1;i++)
    {
        if(i==0)
        {
            if(!strcmp(t,str[i])) occ[i]=1;
            else occ[i]=0;
            continue;
        }
        if(!strcmp(t,str[i])) occ[i]=occ[i-1]+1;
        else occ[i]=occ[i-1];
    }
    //for(int i=0;i<ls-lt+1;i++) cout << occ[i] << " ";
    for(int i=0;i<q;i++)
    {
        if((arr[i][1]-arr[i][0]+1)<lt)
        {
            cout << 0 << endl;
            continue;
        }
        if((arr[i][0]-2)<0) cout << occ[arr[i][1]-lt] << endl;
        else cout << occ[arr[i][1]-lt]-occ[arr[i][0]-2] << endl;
    }

    return 0;
}