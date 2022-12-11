#include<cstdio>
#include<algorithm>

using namespace std;

vector<tuple<int,int,int>> mesArete;
int taille[500*1000];
vector<int> fils[500*1000];
int pere[500*1000];
int valeurStruc[500*1000];
const int NBFEUILLE=1<<20;
const int oo=1e9+5;
vector<int> LCA;

struct noeud{
bool aj=false, del=false;
int m=oo, M=0;
int vm=oo,vM=0;
};
vector<noeud> mesNoeud;

void mettreAj(int b, bool aj){
if(aj){
mesNoeud[b].aj=true;
mesNoeud[b].del=false;
mesNoeud[b].m=mesNoeud[b].vm;
mesNoeud[b].M=mesNoeud[b].vM;
}
else{
mesNoeud[b].aj=false;
mesNoeud[b].del=true;
mesNoeud[b].m=oo;
mesNoeud[b].M=-1;
}
}
void update(int b){
//printf("%d\n", b);
if(b<NBFEUILLE){
if(mesNoeud[b].aj||mesNoeud[b].del){
for(int f=2*b; f<2*b+2;f++){
mettreAj(f, mesNoeud[b].aj);
}
}
mesNoeud[b].aj=false;
mesNoeud[b].del=false;
mesNoeud[b].m=oo;
mesNoeud[b].M=-1;
for(int f=2*b; f<2*b+2;f++){
mesNoeud[b].m=min(mesNoeud[b].m, mesNoeud[f].m);
mesNoeud[b].M=max(mesNoeud[b].M, mesNoeud[f].M);
}
}
}
void ajout(int deb, int fin, bool val, int inf=0, int sup=NBFEUILLE, int base=1){
update(base);
if(deb>=sup || fin<=inf)return;
if(deb<=inf && sup<=fin){
mettreAj(base, val);
return;
}
int mil=(inf+sup)/2;
ajout(deb, fin, val, inf, mil, 2*base);
ajout(deb, fin, val, mil, sup, 2*base+1);
update(base);
}

int tPere(int a){
if(pere[a]==a)return a;
return tPere(pere[a]);
}
int calculLCA(int a, int b){
if(a>b)swap(a,b);
a+=NBFEUILLE;
b+=NBFEUILLE+1;
int rep=-1;
while(a<b){
if(a%2){
rep=max(rep, LCA[a]);
a++;
}
if(b%2){
b--;
rep=max(rep, LCA[b]);
}
a/=2;
b/=2;
}
return rep;
}

int main(){
LCA=vector<int> (2*NBFEUILLE);
mesNoeud=vector<noeud> (2*NBFEUILLE);
int N,Q;
scanf("%d%d",&N,&Q);
for(int i=1;i<N;i++){
int a,b,w;
scanf("%d%d%d", &a, &b, &w);
mesArete.push_back({w,a,b});
}
sort(mesArete.begin(), mesArete.end());
for(int i=0;i<=N;i++){
taille[i]=1;
pere[i]=i;
fils[i].push_back(i);
}

for(auto [w,a,b] : mesArete){
a=tPere(a);
b=tPere(b);
if(taille[a]<taille[b])swap(a,b);
pere[b]=a;
fils[a].push_back(-oo+w);
for(int el :fils[b]){
fils[a].push_back(el);
}
taille[a]+=taille[b];
}
int racine=tPere(1);
/*for(auto el:fils[racine])printf("%d ", el);
printf("\n");
*/
for(int i=0;i<fils[racine].size();i++)if(fils[racine][i]>=0){
valeurStruc[fils[racine][i]]=i;
LCA[NBFEUILLE+i]=-1;
}
else{
LCA[NBFEUILLE+i]=fils[racine][i]+oo;
}
for(int i=NBFEUILLE-1;i>0;i--)LCA[i]=max(LCA[2*i],LCA[2*i+1]);

for(int i=1;i<=N;i++)mesNoeud[NBFEUILLE+i].vm=mesNoeud[NBFEUILLE+i].vM=valeurStruc[i];
for(int i=NBFEUILLE-1;i>0;i--){
mesNoeud[i].vm=min(mesNoeud[2*i].vm,mesNoeud[2*i+1].vm);
mesNoeud[i].vM=max(mesNoeud[2*i].vM,mesNoeud[2*i+1].vM);
}

for(int i=0;i<Q;i++){
int q,a,b;
scanf("%d", &q);
if(q!=3)
scanf("%d%d", &a,&b);
if(q==3)scanf("%d", &a);
if(q==1){
ajout(a, b+1, true);
}
if(q==2){
ajout(a, b+1, false);
}
if(q==3){
int deb = mesNoeud[1].m, fin = mesNoeud[1].M;
if(deb>fin){
printf("-1\n");
continue;
}
//printf("%d %d\n", deb, fin);
int rep = calculLCA(min(deb,valeurStruc[a]), max(valeurStruc[a], fin));
printf("%d\n", rep);
}
}
}