#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

string lol[6]={
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    for(int i=0;i<min(k,4);i++) lol[i+1][1]='O';
    for(int j=0;j<10;j++)
    {
        int AT=2*j+3;
        if(4+j*3+1<=k) lol[1][AT]='O';
        if(4+j*3+2<=k) lol[2][AT]='O';
        if(4+j*3+3<=k) lol[4][AT]='O';
    }

    for(int i=0;i<6;i++) cout<<lol[i]<<endl;
}