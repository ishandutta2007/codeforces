var a:array[0..100000]of longint;
    b,c,d,e,i,f:longint;
begin
 readln(b,c,d,e);
 i:=1;f:=0;a[e]:=1;
 while f=0 do
 begin
  inc(i);
  e:=(b*e+c)mod d;
  if a[e]<>0 then begin writeln(i-a[e]);halt(0);end else a[e]:=i;
 end;
end.