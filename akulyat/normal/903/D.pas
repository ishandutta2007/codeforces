Program CodeF_Edu34_r_D;
const ki=200000; //200000
var place,i,j,n:longint;
    ind:int64;
    full:biginteger;
    w,m,raz,nor:array[1..ki]of int64;
    //reb:array[1..1]of array[1..2]of longint;

procedure swap(a,b:longint);
var c:int64;
begin
   c:=m[a];
   m[a]:=m[b];
   m[b]:=c;
   c:=w[a];
   w[a]:=w[b];
   w[b]:=c;
end;


Procedure q_sort2(a,b:longint);
var p,i,j,q2:longint;
    q:int64;

begin
if b-a>1 then
  begin
    p:=random(b-a+1)+a;
    q:=m[p];
    q2:=w[p];
    swap(p, a);
    i:=a+1;
    j:=b;
      while i<j do
        begin
          while ((m[i]<q) or ((m[i]=q) and  (w[i]<q2) )) and (i<b) do inc(i);
          while (m[j]>q)  or ((m[j]=q) and (w[j]>q2))  do dec(j);
          if i<j then swap(i, j);
        end;    
    swap(a, j);  
    q_sort2(a, j-1);
    q_sort2(j+1, b);
  end                 else
    if (b-a=1) and ((m[a]>m[b]) or ((m[a]=m[b]) and (w[a]>w[b]))) then swap(a, b);
end;  

Function Sk(ind,place:longint):int64;
var a,b,c,d,mi:longint;
begin
  a:=0;
  b:=n+1;

  while a+1<b do
    begin
    mi:=(a+b) div 2; 
    if m[mi]<ind then
      a:=mi else
        b:=mi;
    end;
  if (b=1) and (m[b]>=ind) then
    b:=0;

  c:=0;
  d:=n+1;
  //if m[n]
  
  while c+1<d do
    begin
    mi:=(c+d) div 2;
    if (m[mi]<ind) or ((m[mi]=ind) and (w[mi]<place)) then
      c:=mi else
        d:=mi;
    end;  
  if (d=1) and ((m[d]>ind) or ((m[d]=ind) and (w[d]>place))) then
    d:=0;    
sk:=c-a;  
end;

begin
read(n);
for i:=1 to n do
  begin
  read(m[i]);
  w[i]:=i;
  end;

raz[1]:=0;
for i:=2 to n do
  begin
  raz[i]:=raz[i-1]+(m[i]-m[i-1])*(i-1);
  end;
for i:=1 to n do
  begin
  full:=full+raz[i];
  nor[i]:=m[i];
  end;
//writeln(full);  
q_sort2(1, n); 
for i:=1 to n do
  begin
  place:=i;
  
  ind:=nor[i]-1;
  //writeln(sk(ind,i));
  full:=full-sk(ind, i);
  
  ind:=ind+2;
  //writeln(sk(ind,i));
  full:=full+sk(ind, i);
  
  //writeln;
  end;


{  a:=0;
  b:=n+1;
  while a<>b+1 do
    begin
    mi:=(a+b) div 2;
    if m[mi]<ind then
      a:=mi else
        b:=mi;
    end;
  c:=0;
  d:=n+1;
  while c<>d+1 do
    begin
    mi:=(c+d) div 2;
    if (m[mi]<ind) or ((m[mi]=inda) and (w[mi]<place)) then
      c:=mi else
        d:=mi;
    end;  
  end;
}  
writeln(full);
//for i:=1 to n do
//  writeln(m[i], ' ', w[i]);


end.