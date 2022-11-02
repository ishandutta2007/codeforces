#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

map < string ,int > p;

void read(){
    p["H"]=1;
    p["He"]=2;
    p["Li"]=3;
    p["Be"]=4;
    p["B"]=5;
    p["C"]=6;
    p["N"]=7;
    p["O"]=8;
    p["F"]=9;
    p["Ne"]=10;
    p["Na"]=11;
    p["Mg"]=12;
    p["Al"]=13;
    p["Si"]=14;
    p["P"]=15;
    p["S"]=16;
    p["Cl"]=17;
    p["Ar"]=18;
    p["K"]=19;
    p["Ca"]=20;
    p["Sc"]=21;
    p["Ti"]=22;
    p["V"]=23;
    p["Cr"]=24;
    p["Mn"]=25;
    p["Fe"]=26;
    p["Co"]=27;
    p["Ni"]=28;
    p["Cu"]=29;
    p["Zn"]=30;
    p["Ga"]=31;
    p["Ge"]=32;
    p["As"]=33;
    p["Se"]=34;
    p["Br"]=35;
    p["Kr"]=36;
    p["Rb"]=37;
    p["Sr"]=38;
    p["Y"]=39;
    p["Zr"]=40;
    p["Nb"]=41;
    p["Mo"]=42;
    p["Tc"]=43;
    p["Ru"]=44;
    p["Rh"]=45;
    p["Pd"]=46;
    p["Ag"]=47;
    p["Cd"]=48;
    p["In"]=49;
    p["Sn"]=50;
    p["Sb"]=51;
    p["Te"]=52;
    p["I"]=53;
    p["Xe"]=54;
    p["Cs"]=55;
    p["Ba"]=56;
    p["La"]=57;
    p["Ce"]=58;
    p["Pr"]=59;
    p["Nd"]=60;
    p["Pm"]=61;
    p["Sm"]=62;
    p["Eu"]=63;
    p["Gd"]=64;
    p["Tb"]=65;
    p["Dy"]=66;
    p["Ho"]=67;
    p["Er"]=68;
    p["Tm"]=69;
    p["Yb"]=70;
    p["Lu"]=71;
    p["Hf"]=72;
    p["Ta"]=73;
    p["W"]=74;
    p["Re"]=75;
    p["Os"]=76;
    p["Ir"]=77;
    p["Pt"]=78;
    p["Au"]=79;
    p["Hg"]=80;
    p["Tl"]=81;
    p["Pb"]=82;
    p["Bi"]=83;
    p["Po"]=84;
    p["At"]=85;
    p["Rn"]=86;
    p["Fr"]=87;
    p["Ra"]=88;
    p["Ac"]=89;
    p["Th"]=90;
    p["Pa"]=91;
    p["U"]=92;
    p["Np"]=93;
    p["Pu"]=94;
    p["Am"]=95;
    p["Cm"]=96;
    p["Bk"]=97;
    p["Cf"]=98;
    p["Es"]=99;
    p["Fm"]=100;
}

int n,k;
vector <string> to;
vector <string> from;
map < int , vector < vector <string> > > razl;
int a[200];

void printerr(){
    printf("NO\n");
    exit(0);
}

vector <int> ans;

void printans(){
    printf("YES\n");
    for (int i=0;i<k;++i){
        int num=p[from[i]];
        for (int j=0;j<razl[num][ans[i]].size();++j){
            if (j)
                cout<<"+"<<razl[num][ans[i]][j];
            else cout<<razl[num][ans[i]][j];}
        cout<<"->"<<from[i]<<endl;
    }
    exit(0);
}

int it=0;
ld tim=clock();

void perebor(int pos){
    ++it;
    if (it==5000){
        if ((clock()-tim)/CLOCKS_PER_SEC>2.8)
            printerr();
        it=0;
    }
    if (pos==k)
        printans();
    int num=p[from[pos]];
    for (int i=0;i<razl[num].size();++i){
        int l=razl[num][i].size();
        bool f=true;
        for (int j=0;j<l;++j){
            int m=p[razl[num][i][j]];
            --a[m];
            if (a[m]<0)
                f=false;
        }
        ans.pb(i);
        if (f)
            perebor(pos+1);
        ans.pop_back();
        for (int j=0;j<l;++j){
            int m=p[razl[num][i][j]];
            ++a[m];
        }
    }
}

set < int  > used;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    read();
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;++i){
        string s;
        cin>>s;
        to.pb(s);
        ++a[p[s]];
    }
    sort(to.begin(),to.end());
    for (int i=0;i<k;++i){
        string s;
        cin>>s;
        from.pb(s);
    }
    for (int i=1;i<(1<<n);++i){
        vector <string> tek;
        int h=0;
        tek.clear();
        int num=0;
        for (int j=0;j<n;++j)
            if (i & (1<<j)){
                num+=p[to[j]];
                tek.pb(to[j]);
                for (int z=0;z<to[j].size();++z)
                    h=h*997+to[j][z];
            }
        
        if (used.find(h)==used.end()){
            razl[num].pb(tek);
            used.insert(h);
        }
    }
    perebor(0);
    printerr();
    return 0;
}