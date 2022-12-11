var a:array[0..100100,1..2]of longint;
    x:array[1..100100]of longint;
    y,z,i,ko,tv,f,ml,k,b,c,d:longint;
procedure qsort(l,r:longint);
var i,f,x:longint;
begin
 randomize;i:=l;f:=r;x:=a[random(r-l)+l,1];
 while i<=f do
 begin
  while a[i,1]<x do inc(i);
  while a[f,1]>x do dec(f);
  if i<=f then begin
                y:=a[i,1];
                a[i,1]:=a[f,1];
                a[f,1]:=y;
                y:=a[i,2];
                a[i,2]:=a[f,2];
                a[f,2]:=y;
                inc(i);dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
begin
 tv:=0;
 readln(b,c);
 z:=b;
 if b<c then d:=1 else if b mod c=0 then d:=b div c else d:=b div c+1;
 for i:=1 to d do
 begin
  k:=0;
  while (k<c)and(b>0) do
  begin
   inc(k);
   readln(ml,a[k,1]);
   a[k,2]:=b;
   dec(b);
  end;
  qsort(1,k);
  if ml>tv then tv:=ml;
  ko:=0;
  for f:=1 to k do
   if a[f,1]<>a[f-1,1]then begin ko:=1;x[a[f,2]]:=tv+a[f,1]-a[f-1,1];tv:=tv+a[f,1]-a[f-1,1]+1;end else begin x[a[f,2]]:=x[a[f-1,2]];inc(ko);if ko mod 2=0 then inc(tv);end;
  if b<>0 then tv:=tv+a[k,1];
 end;
 for i:=z downto 1 do
  write(x[i],' ');
end.