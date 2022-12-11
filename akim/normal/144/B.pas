var a:array[1..1000,1..3]of longint;
    x1,y1,x2,y2,k,i,f,s,z:longint;
    log:boolean;
begin
 readln(x1,y1,x2,y2);s:=0;
 if x1>x2 then begin z:=x1;x1:=x2;x2:=z;end;
 if y1<y2 then begin z:=y1;y1:=y2;y2:=z;end;
 readln(k);
 for i:=1 to k do
 begin
  readln(a[i,1],a[i,2],a[i,3]);
  a[i,3]:=a[i,3]*a[i,3];
 end;
 for i:=x1 to x2 do
 begin
  log:=false;
  for f:=1 to k do
  begin
   if sqr(i-a[f,1])+sqr(y1-a[f,2])<=a[f,3] then begin log:=true;break;end;
  end;
  if not(log) then inc(s);
  log:=false;
  for f:=1 to k do
  begin
   if sqr(i-a[f,1])+sqr(y2-a[f,2])<=a[f,3] then begin log:=true;break;end;
  end;
  if not(log) then inc(s);
 end;
 for i:=y2+1 to y1-1 do
 begin
  log:=false;
  for f:=1 to k do
  begin
   if sqr(i-a[f,2])+sqr(x1-a[f,1])<=a[f,3] then begin log:=true;break;end;
  end;
  if not(log) then inc(s);
  log:=false;
  for f:=1 to k do
  begin
   if sqr(i-a[f,2])+sqr(x2-a[f,1])<=a[f,3] then begin log:=true;break;end;
  end;
  if not(log) then inc(s);
 end;
 writeln(s);
end.