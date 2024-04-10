var
 a,b,a1,b1:array[1..1000]of longint;
 fl,i,j,n,m,k,sc,dd:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
procedure sort(l,r:longint);
var i,j,m:longint;
begin
 i:=l;
 j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]>m do inc(i);
  while a[j]<m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  swap(b[i],b[j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
begin
 readln(n);
 randomize;
 for i:=1 to n do begin readln(a[i],b[i]); if a[i]<>b[i] then fl:=1; end;
 if fl=1 then begin writeln('rated'); halt; end;
 for i:=1 to n do begin a1[i]:=a[i]; b1[i]:=b[i]; end;
 sort(1,n);
 for i:=1 to n do if a[i]<>a1[i] then fl:=1;
 if fl=1 then writeln('unrated')else writeln('maybe');
end.