var a:array[0..20]of string;
    b:array[0..400,1..2]of string;
    x,z:array[0..20]of longint;
    i,n,m,p:longint;log:boolean;
function kol:longint;
var i,s:longint;
begin
 s:=0;
 for i:=1 to n do
  if x[i]=1 then inc(s);
 kol:=s;
end;
function posi(s:string):longint;
var i:longint;
begin
 for i:=1 to n do
  if a[i]=s then posi:=i;
end;
procedure qsort(l,r:longint);
var o,z:string;i,f,z1:longint;
begin
 i:=l;f:=r;o:=a[random(r-l)+l];
 while i<=f do
 begin
  while a[i]<o do inc(i);
  while a[f]>o do dec(f);
  if i<=f then begin
                z:=a[i];
                a[i]:=a[f];
                a[f]:=z;
                z1:=x[i];
                x[i]:=x[f];
                x[f]:=z1;
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
begin
 readln(n,m);p:=0;
 for i:=1 to n do
  readln(a[i]);
 qsort(1,n);
 for i:=1 to m do
 begin
  readln(b[i,1]);
  b[i,2]:=copy(b[i,1],pos(' ',b[i,1])+1,length(b[i,1])-pos(' ',b[i,1]));
  delete(b[i,1],pos(' ',b[i,1]),length(b[i,1])-pos(' ',b[i,1])+1);
 end;
 x[1]:=1;
 while x[n+1]<>1 do
 begin
  log:=true;
  for i:=1 to m do
   if (x[posi(b[i,1])]=0)or(x[posi(b[i,2])]=0) then else begin log:=false;break;end;
  if log then if kol>p then begin p:=kol;z:=x;end;
  inc(x[1]);
  for i:=1 to n do
   if x[i]=2 then begin inc(x[i+1]);x[i]:=0;end;
 end;
 writeln(p);
 for i:=1 to n do
  if z[i]=1 then writeln(a[i]);
end.