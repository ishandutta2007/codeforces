var a:array[0..200,0..200]of longint;
    x:array[0..200]of longint;
    och:array[0..200,1..2]of longint;
    i,f,q,n,o,k,l,m,g:longint;log:boolean;
begin
 readln(n,m);
 for i:=1 to m do
 begin
  readln(k,l,m);
  if m=1 then a[k,l]:=1 else a[k,l]:=2;
  a[l,k]:=a[k,l];
 end;
 q:=0;i:=1;o:=0;
 for g:=1 to n do
 begin
  if x[g]=0 then begin inc(q);och[q,1]:=g;och[q,2]:=0;x[1]:=1;end;
  while i<=q do
  begin
   if och[i,2]=1 then
    for f:=1 to n do
     if a[och[i,1],f]=2 then begin a[och[i,1],f]:=1;a[f,och[i,1]]:=1;end else
     if a[och[i,1],f]=1 then begin a[och[i,1],f]:=2;a[f,och[i,1]]:=2;end;
   for f:=1 to n do
    if (a[och[i,1],f]<>0)and(x[f]=0) then begin inc(q);och[q,1]:=f;och[q,2]:=a[och[i,1],f]-1;x[f]:=a[och[i,1],f];if x[f]=2 then inc(o);end;
   inc(i);
  end;
 end;
 log:=true;
 for i:=1 to n do
  for f:=1 to n do
   if a[i,f]=2 then log:=false;
 if log then begin writeln(o); for i:=1 to n do if x[i]=2 then write(i,' ');halt(0);end;
 writeln('Impossible');
end.