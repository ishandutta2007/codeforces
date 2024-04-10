#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev

bool can(int c4,int c7,int c47,int c74,int p){
        if(abs(c47-c74)>1)
                return false;
        if(c47>c4+(p==4)||c47>c7||c74>c7+(p==7)||c74>c4)
                return false;
        if(p==4&&c74>c47||p==7&&c47>c74)
                return false;
        if(p==4&&c7&&!c47)
                return false;
        if(p==7&&c4&&!c74)
                return false;
        if(c47==c74&&c4+(p==4)==c47&&c7+(p==7)==c47)
                return false;
        return true;
}

char res[2100000];

bool solve(int c4,int c7,int c47,int c74){
        if(!can(c4,c7,c47,c74,-1)){
                res[0]='-';
                res[1]='1';
                return true;
        }
        int l=0;
        int p=-1;
        while(c4||c7){
                if(c4&&can(c4-1,c7,c47,c74-(p==7),4)){
                        res[l++]='4';
                        c74-=p==7;
                        --c4;
                        p=4;
                }else{
                        if(!c7||!can(c4,c7-1,c47-(p==4),c74,7)){
                                return false;
                        }
                        res[l++]='7';
                        c47-=p==4;
                        --c7;
                        p=7;
                }
        }
        res[l]=0;
        return true;
}

void stress(){
        forn(c4,20){
                forn(c7,20){
                        forn(c47,20){
                                forn(c74,20){
                                        if(c4&&c7&&c47&&c74&&!solve(c4,c7,c47,c74)){
                                                cout<<"bad "<<c4<<' '<<c7<<' '<<c47<<' '<<c74<<endl;
                                                exit(2);
                                        }
                                }
                        }
                }
        }
        cout<<"ok";
        exit(0);
}

int main(){
#ifdef __ASD__
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

        //ios_base::sync_with_stdio(false);

        //stress();

        int c4,c7,c47,c74;
        cin>>c4>>c7>>c47>>c74;
        if(!solve(c4,c7,c47,c74)){
                cerr<<"oops";
                exit(324);
        }
        printf("%s",res);

        return 0;
}