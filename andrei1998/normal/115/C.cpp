#include <iostream>
#include <string>
#include <vector>

#define mod 1000003
using namespace std;

vector<string> mat1;
vector<string> mat2;

int main()
{
    int n,m;
    cin>>n>>m;

    string aux="";
    mat1.push_back(aux);

    for(int i=1;i<=n;i++){
        cin>>aux;
        aux='#'+aux;

        mat1.push_back(aux);
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mat1[i][j]=='3')
                mat1[i][j]='4';
            else if(mat1[i][j]=='4')
                mat1[i][j]='3';

    mat2=mat1;

    //mat1 e matricea pe coloane
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mat1[i][j]!='.'){
                mat1[i][j]--;

                if((mat1[i][j]-'0')%2==0)
                    mat1[i][j]='0';
                else
                    mat1[i][j]='1';
            }

    //mat2 e matricea pe linii
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mat2[i][j]!='.'){
                mat2[i][j]--;

                if((mat2[i][j]-'0')/2==0)
                    mat2[i][j]='0';
                else
                    mat2[i][j]='1';
            }

    //Intai verificam pe coloane
    vector<bool> col(m+1);
    bool ok=true;

    for(int j=1;j<=m && ok;j++){
        int par=-1;
        int impar=-1;

        for(int i=1;i<=n;i++)
            if(mat1[i][j]!='.'){
                col[j]=1;

                if(i%2==0){
                    if(par==-1)
                        par=mat1[i][j]-'0';
                    else if(mat1[i][j]-'0'!=par){
                        ok=false;
                        break;
                    }
                }
                else{
                    if(impar==-1)
                        impar=mat1[i][j]-'0';
                    else if(mat1[i][j]-'0'!=impar){
                        ok=false;
                        break;
                    }
                }
            }

        if(impar!=-1 && par!=-1)
            if(impar==par){
                ok=false;
                break;
            }
    }

    if(!ok){
        cout<<"0\n";
        return 0;
    }

    //Apoi pe linii
    vector<bool> lin(n+1);

    for(int i=1;i<=n && ok;i++){
        int par=-1;
        int impar=-1;

        for(int j=1;j<=m;j++)
            if(mat2[i][j]!='.'){
                lin[i]=1;

                if(j%2==0){
                    if(par==-1)
                        par=mat2[i][j]-'0';
                    else if(mat2[i][j]-'0'!=par){
                        ok=false;
                        break;
                    }
                }
                else{
                    if(impar==-1)
                        impar=mat2[i][j]-'0';
                    else if(mat2[i][j]-'0'!=impar){
                        ok=false;
                        break;
                    }
                }
            }

        if(impar!=-1 && par!=-1)
            if(impar==par){
                ok=false;
                break;
            }
    }

    if(!ok){
        cout<<"0\n";
        return 0;
    }

    int ans=1;
    for(int i=1;i<=n;i++)
        if(!lin[i]){
            ans*=2;
            if(ans>=mod)
                ans-=mod;
        }

    for(int j=1;j<=m;j++)
        if(!col[j]){
            ans*=2;
            if(ans>=mod)
                ans-=mod;
        }

    cout<<ans<<'\n';
    return 0;
}