Program CodeF_454_A;
var i,n,m1,m2,m3,ma,j,u:longint;
    //reb:array[1..1]of array[1..2]of longint;
    g:boolean;

begin
readln(m1,m2,m3,ma);
for i:=1 to 200 do
  for j:=i+1 to 200 do
    for u:=j+1 to 200 do
      begin
      if (u>=m1) and (u<=2*m1) then
        if (j>=m2) and (j<=2*m2) then
          if (i>=m3) and (i<=2*m3) then
            if (i>=ma) and (j>=ma) and (u>=ma)
              and (2*ma>=i) and (2*ma<j) and (2*ma<u) then
                begin
                writeln(u);
                writeln(j);
                writeln(i);
                exit;
                end;
      end;
writeln(-1);
end.