#include <iostream>
#include <cstring>

using namespace std;

char sir[105];

int main()
{
    cin.get(sir+1,105);
    int n=strlen(sir+1);

    int ans=0;
    int cate=1;

    for(int i=1;i<=n;i++)
        if(sir[i]!=sir[i-1]) {
            ans+=(!(cate&1));
            cate=1;
        }
        else
            cate++;
    ans+=(!(cate&1));

    cout<<ans<<'\n';
    return 0;
}