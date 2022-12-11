var a:array[1..200,1..200]of boolean;
    b,c:array[1..200]of boolean;
    x:array[1..200]of longint;
    tmin,i,f,n,p,t,k,l,num:longint;
function prb:boolean;
var i:longint;
begin
 prb:=false;
 for i:=1 to n do
  if not(b[i]) then begin prb:=true;break;end;
end;
function prbp:boolean;
var i,f:longint;log:boolean;
begin
 prbp:=false;
 for i:=1 to n do
 begin
  log:=false;
  if (x[i]=p)and(not(b[i])) then
  begin
   for f:=1 to n do
    if (not(b[f]))and(a[i,f]) then begin log:=true;break;end;
   if not(log) then begin prbp:=true;num:=i;break;end;
  end;
 end;
end;
begin
 readln(n);tmin:=99999999;
 for i:=1 to n do
  read(x[i]);
 for i:=1 to n do
 begin
  read(k);
  for f:=1 to k do
  begin
   read(l);
   a[i,l]:=true;
  end;
 end;
 p:=1;t:=0;
 while prb do
 begin
  while prbp do
  begin
   b[num]:=true;
   t:=t+1;
  end;
  inc(p);inc(t);
  if p=4 then p:=1;
 end;
 if t<tmin then tmin:=t;
 p:=2;t:=0;b:=c;
 while prb do
 begin
  while prbp do
  begin
   b[num]:=true;
   t:=t+1;
  end;
  inc(p);inc(t);
  if p=4 then p:=1;
 end;
 if t<tmin then tmin:=t;
 p:=3;t:=0;b:=c;
 while prb do
 begin
  while prbp do
  begin
   b[num]:=true;
   t:=t+1;
  end;
  inc(p);inc(t);
  if p=4 then p:=1;
 end;
 if t<tmin then tmin:=t;
 writeln(tmin-1);
end.