program Projecta;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type sco=record
      s:string;
      k,p:integer;
      b:array[1..1000,1..2]of integer
     end;
var a:array[0..2000]of sco;
    n,l,i,j,q,maxn,d,max,minp,sum:integer;
    f:boolean;
    c:char;
    s:string;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readln(n);
 l:=0;
 a[0].k:=-maxint;
 a[0].p:=maxint;
 for i:=1 to n do begin
  read(c);
  s:='';
  while c<>' ' do begin
   s:=s+c;
   read(c)
  end;
  f:=false;
  for j:=1 to l do
   if s=a[j].s then begin
    f:=true;
    break
   end;
  if not f then begin
   inc(l);
   j:=l;
   a[j].s:=s;
  end;
  f:=false;
  read(c);
  if c='-' then begin
   f:=true;
   read(c)
  end;
  d:=ord(c)-ord('0');
  while not seekeoln do begin
   read(c);
   d:=d*10+ord(c)-ord('0')
  end;
  readln;
  if f then d:=-d;
  a[j].k:=a[j].k+d;
  a[j].p:=a[j].p+1;
  a[j].b[a[j].p,1]:=d;
  a[j].b[a[j].p,2]:=i
 end;
 max:=-maxint;
 for i:=1 to l do
  if (a[i].k>max)then max:=a[i].k;
 maxn:=0;
 minp:=maxint;
 for i:=1 to l do
  if a[i].k=max then begin
   sum:=0;
   j:=0;
   while sum<max do begin
    inc(j);
    sum:=sum+a[i].b[j,1]
   end;
   if a[i].b[j,2]<minp then begin
    minp:=a[i].b[j,2];
    maxn:=i
   end
  end;
 writeln(a[maxn].s);
end.