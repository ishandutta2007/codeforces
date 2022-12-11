var a:array[1..100000]of longint;
    b:array[1..1000,1..2]of longint;
    n,k,l,o,i,f,q,sq:longint;
procedure rek(q,z:longint);
begin
 if a[z]=0 then begin inc(o);a[z]:=f;end else
  if f-l>a[z] then begin inc(o);a[z]:=f;end else
   a[z]:=f;
 for q:=q downto 1 do
  if b[q,2]>0 then begin dec(b[q,2]);rek(q,z*b[q,1]);inc(b[q,2]);end;
end;
begin
 readln(n);
 for f:=1 to n do
 begin
  readln(k,l);o:=0;
  i:=2;q:=0;sq:=trunc(sqrt(k))+1;
  while i<=sq do
  begin
   if k mod i=0 then
   begin
    inc(q);
    b[q,1]:=i;b[q,2]:=0;
    while k mod i=0 do
    begin
     k:=k div i;
     inc(b[q,2]);
    end;
    sq:=trunc(sqrt(k))+1;
   end;
   inc(i);
  end;
  if k>1 then begin inc(q);b[q,1]:=k;b[q,2]:=1;end;
  rek(q,1);
  writeln(o);
 end;
end.