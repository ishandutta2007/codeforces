Program asewf;
const ki=10000;
type massiv=array[0..ki+2]of longint;
var j,max,i,n,kol:longint;
    de,p,c,m:massiv;
    //k,r:array[0..ki+2]of massiv;
    //reb:array[1..1]of array[1..2]of longint;

begin
read(n);
for i:=2 to n do
  begin
  read(p[i]);
  //inc(de[p[i]]);
  //k[p[i]][de[p[i]]]:=i;
  end;

kol:=n;
for i:=1 to n do
  begin
  read(c[i]);
  if c[i]=c[p[i]] then
  dec(kol);  
  end;

writeln(kol);


end.