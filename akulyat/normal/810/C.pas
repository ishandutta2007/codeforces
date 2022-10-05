Program YaBaran;
const p=1000000007;
var ans:int64;
    st2,mas,r:array[0..300010]of int64;
    n,i,j:longint;

procedure swap(a,b:longint);
var c:int64;
begin
   c:=mas[a];
   mas[a]:=mas[b];
   mas[b]:=c;
end;


Procedure q_sort2(a,b:longint);
var p,i,j:longint;
    q:int64;

begin
if b-a>1 then
  begin
    p:=random(b-a+1)+a;
    q:=mas[p];
    swap(p, a);
    i:=a+1;
    j:=b;
      while i<j do
        begin
          while (mas[i]<=q) and (i<b) do inc(i);
          while mas[j]>q  do dec(j);
          if i<j then swap(i, j);
        end;    
    swap(a, j);  
    q_sort2(a, j-1);
    q_sort2(j+1, b);
  end                 else
    if (b-a=1) and (mas[a]>mas[b]) then swap(a, b);
end;  



begin
read(n);
st2[0]:=1;
for i:=1 to 300000 do
  st2[i]:=st2[i-1]*2 mod p;
for i:=1 to n do
  begin
  read(mas[i]);
  end;
q_sort2(1, n);
for i:=2 to n do
  begin
  r[i-1]:=mas[i]-mas[i-1];
  ans:=(ans+(((st2[i-1]-1)*(st2[n-i+1]-1))mod p)*r[i-1] mod p)mod p;
  end;
writeln(ans);
end.