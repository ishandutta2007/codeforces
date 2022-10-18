uses math;
var
  gr:array[0..1000,0..1000]of longint;
  a,n,m,kil1,kil2:longint;
  i,j:longint;
  label 1,2;
begin
  read(a,n,m);
  for i:=1 to n do
    for j:=1 to m do
      if kil1<>a div 2+sign(a mod 2) then
        begin
          if not odd(i+j) then begin gr[i,j]:=kil1*2+1; inc(kil1); end;
        end
      else goto 1;
  1:

  for i:=1 to n do
    for j:=1 to m do
      if kil2<>a div 2 then
        begin
          if (odd(gr[i-1,j]) or (gr[i-1,j]=0)) and (odd(gr[i+1,j]) or (gr[i+1,j]=0))
            and (odd(gr[i,j-1]) or (gr[i,j-1]=0)) and (odd(gr[i,j+1]) or (gr[i,j+1]=0))
              and (gr[i,j]=0) then begin gr[i,j]:=(kil2+1)*2; inc(kil2); end;
        end
      else goto 2;
  2:

  if (kil1<>a div 2+sign(a mod 2)) or (kil2<>a div 2) then
    begin
      writeln(-1);
      halt
    end;

  for i:=1 to n do
    begin
      for j:=1 to m do
        write(gr[i,j],' ');
      writeln;
    end;
end.