type
 tarray=array[1..200000]of longint;
var
 a,b,c,v:tarray;
 n,i,j,k,sc,sc1,lm,pz:longint;
 su:int64;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;

procedure sort(l,r:longint; var a,b,c:tarray);
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
  swap(b[i],b[j]);
  swap(c[i],c[j]);
  inc(i);
  dec(j);
 until i>j;
 if i<r then sort(i,r,a,b,c);
 if l<j then sort(l,j,a,b,c);
end;

procedure qsort(l,r:longint);
var i,j,m,cc:longint;
begin
 i:=l;
 j:=r;
 cc:=l+random(r-l+1);
 m:=a[cc]-b[cc];
 repeat
  while a[i]-b[i]<m do inc(i);
  while a[j]-b[j]>m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  swap(b[i],b[j]);
  swap(c[i],c[j]);
  inc(i);
  dec(j);
 until i>j;
 if i<r then qsort(i,r);
 if l<j then qsort(l,j);
end;

begin
 randomize;
 readln(n,k);
 for i:=1 to n do read(a[i]); readln;
 for i:=1 to n do read(b[i]);
 for i:=1 to n do if b[i]<a[i] then c[i]:=1;
 sort(1,n,c,a,b);

 for i:=1 to n do if c[i]=0 then inc(sc);
 if sc>=k then
 begin
  for i:=1 to n do if c[i]=0 then su:=su+a[i] else su:=su+b[i];
  writeln(su);
  halt;
 end;
 for i:=1 to n do if c[i]=1 then begin pz:=i; break; end;
 qsort(pz,n);
 su:=0;
 for i:=1 to k do su:=su+a[i];
 for i:=k+1 to n do su:=su+b[i];
 writeln(su);
end.