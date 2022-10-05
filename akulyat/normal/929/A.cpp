#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream in;
    //ofstream out;

    //in.open("input.txt");
    //out.open("output.txt");


    long long n,k,mass[100010],otv=1;

    cin >> n >> k;

    for (long long i=0; i<n; i++){
        cin >>mass[i];
    }
    for (long long i=1; i<n; i++){
        if (mass[i]-mass[i-1]>k) {otv=-1;}
    }

    long long j=0,tec=mass[0]+k;


    if (otv==-1) {cout << otv;}
    else
    {
        while (j<n) {
            while ((j<n)&&(mass[j]<=tec)) {j++;};
            if (j!=n) {
                otv++;
                tec=mass[j-1]+k;
                //cout <<tec;
            }
        }
        cout <<otv;
    }






    return 0;
}