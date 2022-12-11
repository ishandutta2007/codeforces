var a:array[0..1000000]of boolean;
    b:array[0..1000000]of longint;
    i,f,l,x,y,k:longint;
begin
 a[1]:=true;
 for i:=2 to 1000000 do
  if not(a[i]) then
  begin
   f:=i*2;
   while f<=1000000 do begin a[f]:=true;f:=f+i;end;
  end;
 for i:=2 to 1000000 do
  if not(a[i]) then b[i]:=b[i-1]+1 else b[i]:=b[i-1];
 readln(x,y,k);
 l:=0;
 for i:=x to y do
  if b[i]-b[x-1]=k then begin l:=i-x+1;break;end;
 if l=0 then begin writeln('-1');halt(0);end;
 for i:=x+l to y do
  if b[i]-b[i-l]<k then inc(l);
 writeln(l);
end.