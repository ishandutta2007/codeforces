Program Konfeti;
type massiv=array[0..200010]of longint;
var m,mas:massiv;
    n,nk,b,kol,i,nul,nen:longint; 
    kva:array[0..100000]of longint;
    otv:int64;    
    
Function Bliz(i:longint):longint;
var m,itog,a:longint;
begin
b:=round(sqrt(1000000000))+1;
a:=0;
while a+1<>b do
  begin
  m:=(a+b) div 2;
  if kva[m]<=i then
    a:=m else
    b:=m;
  end;

itog:=min(abs(i-kva[a]), abs(i-kva[b]));
Bliz:=itog;
end;

procedure swap(a,b:longint);
var x:int64;
begin
x:=mas[a];
mas[a]:=mas[b];
mas[b]:=x;
end;

Procedure q_sort(var e:massiv; a,b:longint);
var i,j,k,t:longint;
    q:int64;
begin

if a>=b then
else
  begin
    t:=random(b-a+1)+a;
    q:=e[t];
    swap(a, t);
    i:=a; j:=a+1; k:=b;
    while j<=k do
      if e[j]=q then inc (j)
        else
        if e[j]<q then
          begin
          swap(i, j);
          inc(i);
          inc(j);
          end
            else  
              begin
              swap(j,k);
              dec(k);
              end;
   q_sort(e, a, i-1);
   q_sort(e, k+1, b);
  end;
end;  




begin
b:=round(sqrt(1000000000))+1;
for i:=0 to b do
  kva[i]:=sqr(i);
{writeln(bliz(17));  
writeln(bliz(0));
writeln(bliz(1));
writeln(bliz(20));
writeln(bliz(21));  }
read(n);
for i:=1 to n do
  begin
  read(m[i]);
  if sqr(round(sqrt(m[i])))=m[i] then inc(kol);
  if m[i]=0 then
    inc(nul);
  end;
//  writeln(kol);
if kol>=n div 2 then
  begin
  nen:=kol-nul;
  kol:=kol-(n div 2);
  if nen>= kol then
    begin
    writeln(kol);
    exit;
    end;
  writeln(nen+(kol-nen)*2);  
  exit;
  end;

for i:=1 to n do
  begin
  if sqr(round(sqrt(m[i])))<>m[i] then
    begin
    inc(nk);
//    writeln(m[i]);
    mas[nk]:=bliz(m[i]);
    end;
  end;
//writeln(nk);
q_sort(mas, 1, nk);
//for i:=1 to nk do
  //write(mas[i], ' ');
for i:=1 to (n div 2)-kol do
  begin
  otv:=otv+mas[i];
  end;
writeln(otv);  
end.