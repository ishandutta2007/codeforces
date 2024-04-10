#include<iostream>
#include<stdlib.h>
#include<time.h>
#define INF 1000000001
using namespace std;
int q, i, t, x, k, nr1, n;
long long sol, sum;
struct nod{
    nod *st, *dr;
    int nr, nr1, val, vp, t;
    long long sum;
    nod(int val, int vp, int nr, int nr1, long long sum, nod *st, nod *dr){
        this->nr = nr;
        this->t = this->nr1 = nr1;
        this->sum = sum;
        this->val = val;
        this->vp = vp;
        this->st = st;
        this->dr = dr;
    }
};
nod *r, *nill;
void update(nod *r){
   r->nr = 1 + r->st->nr + r->dr->nr;
   r->nr1 = r->t + r->st->nr1 + r->dr->nr1;
   r->sum = r->val + r->st->sum + r->dr->sum;
}
void rotst(nod * &r){
    nod *aux = r->st;
    r->st = aux->dr;
    aux->dr = r;
    r = aux;
    update(r->dr);
    update(r);
}
void rotdr(nod * &r){
    nod *aux = r->dr;
    r->dr = aux->st;
    aux->st = r;
    r = aux;
    update(r->st);
    update(r);
}
void gettr(nod * &r){
    if(r->st->vp > r->vp){
        rotst(r);
    }
    else{
        if(r->dr->vp > r->vp){
            rotdr(r);
        }
    }
}
void addtr(nod * &r, int x, int t){
    if(r == nill){
        r = new nod(x, rand() % INF + 1, 1, t, x, nill, nill);
    }
    else{
        if(r->val > x){
            addtr(r->st, x, t);
        }
        else{
            if(r->val < x){
                addtr(r->dr, x, t);
            }
        }
        gettr(r);
        update(r);
    }
}
void deltr(nod * &r, int x){
    if(r != nill){
        if(r->val == x){
            if(r->st == nill && r->dr == nill){
                delete r;
                r = nill;
            }
            else{
                if(r->st->vp > r->dr->vp){
                    rotst(r);
                }
                else{
                    rotdr(r);
                }
                deltr(r, x);
            }
        }
        else{
            if(r->val > x){
                deltr(r->st, x);
            }
            else{
                deltr(r->dr, x);
            }
        }
        if(r != nill){
            update(r);
        }
    }
}
long long sumtr(nod *r, int p){
    if(r == nill){
        return 0;
    }
    if(r->dr->nr >= p){
        return sumtr(r->dr, p);
    }
    else{
        return r->dr->sum + r->val + sumtr(r->st, p - r->dr->nr - 1);
    }
}
int nr1tr(nod *r, int p){
    if(r == nill){
        return 0;
    }
    if(r->dr->nr >= p){
        return nr1tr(r->dr, p);
    }
    else{
        return r->dr->nr1 + r->t + nr1tr(r->st, p - r->dr->nr - 1);
    }
}
int srctr(nod *r, int nr1){
    if(r->dr->nr1 + 1 == nr1 && r->t == 1){
        return r->val;
    }
    else{
        if(r->dr->nr1 >= nr1){
            return srctr(r->dr, nr1);
        }
        else{
            return srctr(r->st, nr1 - r->dr->nr1 - r->t);
        }
    }
}
int main(){
    srand( time(0));
    r = nill = new nod(0, 0, 0, 0, 0, NULL, NULL);
    cin>> q;
    for(; q; q--){
        cin>> t >> x;
        sum += x;
        if(x < 0){
            deltr(r, -x);
            k -= t;
            n--;
        }
        else{
            addtr(r, x, t);
            k += t;
            n++;
        }
        nr1 = nr1tr(r, k);
        if(k == 0){
            sol = sum;
        }
        else{
            if(nr1 == k){
                sol = sum + sumtr(r, k + 1) - srctr(r, k);
            }
            else{
                sol = sum + sumtr(r, k);
            }
        }
        cout<< sol <<"\n";
    }
}