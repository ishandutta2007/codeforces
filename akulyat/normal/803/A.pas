Program CodeF_Edu20_A;
const matr=100; 
var pol:array[1..matr]of array[1..matr]of longint;
    n,k,i,j,a,b,m,k1:longint;
begin
read(n,k);
if k>n*n then write(-1) else
  begin
    for i:=1 to n do
      for j:=i to n do
        begin
          if (i=j) and (k>0) then 
            begin
              dec(k);
              pol[i][j]:=1;
            end;  
          if (i<>j) and (k>1) then
            begin
              k:=k-2;
              pol[i][j]:=1;
              pol[j][i]:=1;
            end;
        end;
    for i:=1 to n do
      begin
        writeln;
        for j:=1 to n do
          write(pol[i][j], ' ');
      end;
  end;    
end.