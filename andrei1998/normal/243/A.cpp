#include <iostream>
#include <algorithm>

using namespace std;

int v[100005];
int din[20][100005]; //Prima locatie unde apare un bit de (1<<i) dupa j

int frecv[1048580];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=0;i<20;i++){
        din[i][n+1]=n+1;
        for(int j=n;j>=1;j--){
            if((v[j]&(1<<i))!=0)
                din[i][j]=j;
            else
                din[i][j]=din[i][j+1];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){ //Variem pozitia de inceput
        int curent=0;
        int j=i;

        while(j<=n){
            curent|=v[j];
            if(!frecv[curent])
                ans++;
            frecv[curent]=1;

            int minim=(n+1);
            for(int k=0;k<20;k++)
                if(!(curent&(1<<k)))
                    if(din[k][j]<minim)
                        minim=din[k][j];
            j=minim;
        }
    }

    cout<<ans<<'\n';
    return 0;
}