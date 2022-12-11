type new=record
          n:string;
          s:longint;
         end;
var a:array[-5..1000]of new;
    n,k,i,f,r,l:longint;
    vr:new;
    c:char;
    log:boolean;
    pr:real;
begin
 readln(n);k:=0;
 for f:=1 to n do
 begin
  vr.n:='';read(c);
  while c<>' ' do
  begin
   vr.n:=vr.n+c;
   read(c);
  end;
  readln(vr.s);
  log:=true;
  for i:=1 to k do
  if a[i].n=vr.n then begin log:=false;if a[i].s<vr.s then a[i].s:=vr.s;end;
  if log then begin inc(k);a[k]:=vr;end;
 end;
 for i:=1 to k-1 do
  for f:=i to k do
  if a[i].s>a[f].s then begin vr:=a[i];a[i]:=a[f];a[f]:=vr;end;
 a[0].s:=-100;
 writeln(k);
 for i:=1 to k do
 begin
{  l:=i-1;}
  r:=i;
{  while a[l].s=a[i].s do
   dec(l);}
  while a[r].s=a[i].s do
   inc(r);
  r:=k-r+1;
  if k-r<k*0.5 then writeln(a[i].n,' noob') else
  if k-r<k*0.8 then writeln(a[i].n,' random') else
  if k-r<k*0.9 then writeln(a[i].n,' average') else
  if k-r<k*0.99 then writeln(a[i].n,' hardcore') else
  writeln(a[i].n,' pro');
 end;
end.