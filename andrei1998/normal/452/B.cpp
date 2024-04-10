#include <iostream>
#include <cmath>

using namespace std;

struct punct
{
    int x,y;
    punct(int a=0,int b=0): x(a), y(b) {}
};

bool operator!=(punct a,punct b)
{
    return (a.x!=b.x || a.y!=b.y);
}

long double dist(punct a,punct b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int n,m;
    cin>>n>>m;

    if(!n){
        cout<<"0 1\n";
        cout<<"0 "<<m<<'\n';
        cout<<"0 0\n";
        cout<<"0 "<<m-1<<'\n';

        return 0;
    }

    if(!m){
        cout<<"1 0"<<endl;
        cout<<n<<' '<<0<<endl;
        cout<<"0 0"<<endl;
        cout<<n-1<<' '<<0<<endl;
        return 0;
    }

    //Sol1
    punct a(1,0);
    punct b(n,m);
    punct c(0,0);
    punct d(n-1,m);

    long double aux1=dist(a,b)+dist(b,c)+dist(c,d);

    //Sol2
    punct e(0,0);
    punct f(n,m);
    punct g(0,m);
    punct h(n,0);

    long double aux2=dist(e,f)+dist(f,g)+dist(g,h);

    //Sol3
    punct t(0,0);
    punct tt(n,m);
    punct ttt(n,0);
    punct tttt(0,m);

    long double aux3=dist(t,tt)+dist(tt,ttt)+dist(ttt,tttt);

    //Sol4
    punct y(n,m-1);
    punct yy(0,0);
    punct yyy(n,m);
    punct yyyy(0,1);

    long double aux4=dist(y,yy)+dist(yy,yyy)+dist(yyy,yyyy);

    if(aux1>=aux2 && aux1>=aux3 && aux1>=aux4){
        cout<<a.x<<' '<<a.y<<endl;
        cout<<b.x<<' '<<b.y<<endl;
        cout<<c.x<<' '<<c.y<<endl;
        cout<<d.x<<' '<<d.y<<endl;
    }
    else if(aux2>=aux1 && aux2>=aux3 && aux2>=aux4){
        cout<<e.x<<' '<<e.y<<endl;
        cout<<f.x<<' '<<f.y<<endl;
        cout<<g.x<<' '<<g.y<<endl;
        cout<<h.x<<' '<<h.y<<endl;
    }
    else if(aux3>=aux1 && aux3>=aux2 && aux3>=aux4){
        cout<<t.x<<' '<<t.y<<endl;
        cout<<tt.x<<' '<<tt.y<<endl;
        cout<<ttt.x<<' '<<ttt.y<<endl;
        cout<<tttt.x<<' '<<tttt.y<<endl;
    }
    else{
        cout<<y.x<<' '<<y.y<<endl;
        cout<<yy.x<<' '<<yy.y<<endl;
        cout<<yyy.x<<' '<<yyy.y<<endl;
        cout<<yyyy.x<<' '<<yyyy.y<<endl;
    }

    return 0;
}