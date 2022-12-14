var
 a:array[1..100000]of int64;
 mn,ln,n,m,b,c,sc,k:int64;
 i,j:Longint;
procedure swap(var a,b:int64);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
procedure sort(l,r:longint);
var i,j:longint; m:int64;
begin
 i:=l;
 j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
begin
 randomize;
 readln(n,k);
 mn:=trunc(1e15);
 for i:=1 to n do begin read(a[i]);  if a[i]<mn then mn:=a[i]; end;
// sort(1,n);


 for i:=1 to n do if a[i]<>mn then
 begin
  ln:=a[i]-mn;
  if ln mod k<>0 then begin writeln(-1); halt; end;
  sc:=sc+ln div k;
 end;
 writeln(sc);
end.