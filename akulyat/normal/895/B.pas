Program CodeF_448_B;
const ki=100010;
type massiv=array[1..ki+3]of int64;
var s,a1,a2,b1,b2,me,i,n:longint;
    m:massiv;
    //reb:array[1..1]of array[1..2]of longint;
   mi,ma,kol,x,k,a,b:int64;
   f:text; 
   
procedure swap(a,b:longint);
var x:int64;
begin
x:=m[a];
m[a]:=m[b];
m[b]:=x;
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
read(n,x,k);
for i:=1 to n do
  begin
  read( m[i]);
  end;
q_sort(m, 1, n);

for i:=1 to n do
  begin
  if k=0 then
    begin
    mi:=m[i];
    if mi mod x=0 then
      ma:=mi-1 else
      ma:=mi-(mi mod x)+x-1;
    end else
      begin
      mi:=m[i]-(m[i] mod x);
      mi:=mi+k*x;
      if m[i] mod x=0 then mi:=mi-x;
      ma:=mi+x-1;
      end;
//    writeln(mi, ' ', ma );  
    a1:=0;
    b1:=n+1;
    while a1+1<>b1 do
      begin
      me:=(a1+b1)div 2;
      if m[me]<mi then
        a1:=me else
        b1:=me;
      end;  
    a2:=0;
    b2:=n+1;
    while a2+1<>b2 do
      begin
      me:=(a2+b2)div 2;
      if m[me]<=ma then
        a2:=me else
        b2:=me;
      end;
//  writeln(a2, ' ', b1);   
  kol:=kol+a2-b1+1;            
  //writeln(i);
  end;
writeln(kol);


end.