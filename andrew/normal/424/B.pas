procedure swap(var a,b:extended);
var
 c:extended;
begin
 c:=a;
 a:=b;
 b:=c;
end;
var
 l,k1:array[1..10000]of extended;
 k,x,y,x1,y1:extended;
 n,i,j:longint;
begin
 readln(n,k);
 for i:=1 to n do
 begin
  readln(x1,y1,k1[i]);
  l[i]:=sqrt(sqr(x1-x)+sqr(y1-y));
 end;

 for i:=1 to n-1 do
 for j:=i+1 to n do if l[i]>l[j] then
 begin
  swap(l[i],l[j]);
  swap(k1[i],k1[j]);
 end;
 for i:=1 to n do
 begin
  k:=k+k1[i];
  if k>=1000000 then begin writeln(l[i]:0:7); halt; end;
 end;
 writeln(-1);
end.