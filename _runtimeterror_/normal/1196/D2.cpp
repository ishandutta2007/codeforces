#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    string t("RGB");
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<vector<int>> v(3,vector<int>(n+1,0)); 
        auto f=[&](int i){

            for(int k=0;k<n;++k)
            {
                v[i][k+1]=v[i][k]+(s[k]!=t[(i+k)%3]);
            }
        };
        f(0);f(1);f(2);
        int ans=n;
        for(int i=0;i<n;++i)
        {
            if(i+k>n)
                break;
            for(int j=0;j<3;++j)
                ans=min(ans,v[j][i+k]-v[j][i]);
        }
        cout << ans << '\n';
    }
}