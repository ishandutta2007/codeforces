var a:array[1..12]of longint;
    k,i,f,x:longint;
begin
 readln(k);
 for i:=1 to 12 do
  read(a[i]);
 for i:=1 to 11 do
  for f:=i+1 to 12 do
  if a[i]<a[f] then begin
                     x:=a[i];
                     a[i]:=a[f];
                     a[f]:=x;
                    end;
 if k=0 then begin writeln(0);halt(0);end;
 for i:=1 to 12 do
 begin
  if k>0 then k:=k-a[i] else begin writeln(i-1);halt(0);end;
 end;
 if k<=0 then writeln('12') else writeln('-1');
end.