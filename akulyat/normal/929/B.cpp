#include <bits/stdc++.h>

using namespace std;


 long long n,k,res[5],res1[5],otv=0;
 char mass[110][12];

void prov(long long i,long long j)
{
    if (mass[i][j]=='S'){
        if ((j==11)&&((mass[i][j-1]=='P')||(mass[i][j-1]=='S'))) otv++;
        if ((j==0)&&((mass[i][j+1]=='P')||(mass[i][j+1]=='S'))) otv++;
        if ((j!=0)&&(j!=11)){
            if ((mass[i][j+1]=='P')||(mass[i][j+1]=='S')) otv++;
            if ((mass[i][j-1]=='P')||(mass[i][j-1]=='S')) otv++;
        }
    }
    if (mass[i][j]=='.'){
        if (j==11){
            if (mass[i][j-1]=='S') res[1]++;
                else res[0]++;
        }

        if (j==0){
            if (mass[i][j+1]=='S') res[1]++;
            else res[0]++;
        }

        if ((j!=0)&&(j!=11)){
            if ((mass[i][j+1]=='S')&&(mass[i][j-1]=='S')) res[2]++;
                else {
                        if ((mass[i][j+1]=='S')||(mass[i][j-1]=='S'))
                        res[1]++;
                     else res[0]++;
                     }
        }
    }
}



long long prov2(long long i,long long j)
{
        long long otvet=0;
     if (mass[i][j]=='.'){
        if (j==11){
            if (mass[i][j-1]=='S') otvet=1;
                else otvet=0;
        }

        if (j==0){
            if (mass[i][j+1]=='S') otvet=1;
            else otvet=0;
        }

        if ((j!=0)&&(j!=11)){
            if ((mass[i][j+1]=='S')&&(mass[i][j-1]=='S')) otvet=2;
                else {
                        if ((mass[i][j+1]=='S')||(mass[i][j-1]=='S'))
                        otvet=1;
                     else otvet=0;
                     }
        }
     }
    return otvet;
}



int main()
{
    //ifstream in;
    //ofstream out;
    //in.open("input.txt");
    //out.open("output.txt");


    cin >>n>>k;

    for (long long i=0; i<n;i++){
        for (long long j=0;j<12;j++){
            cin >>mass[i][j];
        }
    }
    res[0]=0;
    res[1]=0;
    res[2]=0;
    res1[0]=0;
    res1[1]=0;
    res1[2]=0;

    for (long long i=0; i<n;i++){
        for (long long j=0;j<12;j++){
         prov(i,j);
        }
    }
    //cout <<res[0]<<' '<<res[1]<<' '<<res[2]<<' '<<otv<<endl;

    if (k<=res[0]){
        res1[0]=k;
    }

    if ((k>res[0])&&(k<=res[0]+res[1])){
        res1[0]=res[0];
        res1[1]=k-res[0];
    }

    if (k>res[0]+res[1]){
        res1[0]=res[0];
        res1[1]=res[1];
        res1[2]=k-res[0]-res[1];
    }
    cout <<otv+res1[1]+res1[2]*2<<endl;



    for (long long i=0; i<n;i++){
        for (long long j=0;j<12;j++){
            if (mass[i][j]=='.'){
                long long t=prov2(i,j);
                if (res1[t]!=0){
                    cout <<'x';
                    res1[t]--;
                } else cout <<'.';
            } else cout <<mass[i][j];
        } if (i!=n-1) cout<<endl;
    }


    return 0;
}