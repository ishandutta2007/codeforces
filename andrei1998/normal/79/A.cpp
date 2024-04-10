#include <iostream>

using namespace std;

int x,y;

bool perform_ciel() {
    if(x>=2 && y>=2) {
        x-=2;
        y-=2;
        return true;
    }
    else if(x>=1 && y>=12) {
        x-=1;
        y-=12;
        return true;
    }
    else if(y>=22) {
        y-=22;
        return true;
    }

    return false;
}

bool perform_hanako() {
    if(y>=22) {
        y-=22;
        return true;
    }
    else if(x>=1 && y>=12) {
        x-=1;
        y-=12;
        return true;
    }
    else if(x>=2 && y>=2) {
        x-=2;
        y-=2;
        return true;
    }

    return false;
}

int main()
{
    cin>>x>>y;

    while(1) {
        if(!perform_ciel()) {
            cout<<"Hanako\n";
            return 0;
        }
        if(!perform_hanako()) {
            cout<<"Ciel\n";
            return 0;
        }
    }

    return 0;
}