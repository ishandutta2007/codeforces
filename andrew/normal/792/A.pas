var
 a,b:array[0..200000]of longint;
 min,i,j,ch1,ch2,ch3,sc,sc1,i1,j1,k,n,m:longint;
 s,s1:ansistring;
procedure swap(var a,b:Longint);
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
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r);
 if j>l then sort(l,j);
end;
begin
 randomize;
 readln(n);
 for i:=1 to n do read(a[i]);
 sort(1,n);
 m:=maxlongint;
 for i:=2 to n do if abs(a[i]-a[i-1])<m then begin m:=abs(a[i]-a[i-1]); k:=1; end
  else if m=abs(a[i]-a[i-1])then inc(k);

 writeln(m,' ',k);
end.