VAR
  n, i, j, k, ans: LONGINT;
  Mas: ARRAY[0..500,0..500] OF LONGINT;
  M: ARRAY[0..600,0..300,0..300] OF LONGINT;
BEGIN
  READLN(n);
  FOR i := 1 TO N DO
    FOR j := 1 TO N DO
      READ(Mas[j,i]);
  M[1,1,1] := Mas[1,1];
  FOR i := 2 TO N DO
    FOR j := 1 TO i DO
      FOR k := 1 TO i DO
        BEGIN
          IF j=k
          THEN
            BEGIN
              IF (j<i) AND (k<i)
              THEN
                M[i,j,k] := M[i-1,j,k]+Mas[i-j+1,j]
              ELSE
                M[i,j,k] := -100000000;
              IF (j>1) AND (k<i) AND (M[i,j,k]<M[i-1,j-1,k]+Mas[i-j+1,j])
              THEN
                M[i,j,k] := M[i-1,j-1,k]+Mas[i-j+1,j];
              IF (j>1) AND (M[i,j,k]<M[i-1,j-1,k-1]+Mas[i-j+1,j])
              THEN
                M[i,j,k] := M[i-1,j-1,k-1]+Mas[i-j+1,j];
            END
          ELSE
            BEGIN             
              IF (j<i) AND (k<i)
              THEN
                M[i,j,k] := M[i-1,j,k]
              ELSE
                M[i,j,k] := -100000000;
              IF (j>1) AND (k<i) AND (M[i,j,k]<M[i-1,j-1,k])
              THEN
                M[i,j,k] := M[i-1,j-1,k];
              IF (j>1) AND (k>1) AND (M[i,j,k]<M[i-1,j-1,k-1])
              THEN
                M[i,j,k] := M[i-1,j-1,k-1];
              IF (k>1) AND (j<i) AND (M[i,j,k]<M[i-1,j,k-1])
              THEN
                M[i,j,k] := M[i-1,j,k-1];
              M[i,j,k] := M[i,j,k]+Mas[i-j+1,j]+Mas[i-k+1,k];
            END;
        END;
  FOR i := N+1 TO 2*N-1 DO
    FOR j := i-N+1 TO N DO
      FOR k := i-N+1 TO N DO
        BEGIN
          IF j=k
          THEN
            BEGIN
              M[i,j,k] := M[i-1,j,k]+Mas[i-j+1,j];
              IF (j>1) AND (M[i,j,k]<M[i-1,j-1,k]+Mas[i-j+1,j])
              THEN
                M[i,j,k] := M[i-1,j-1,k]+Mas[i-j+1,j];
              IF (j>1) AND (M[i,j,k]<M[i-1,j-1,k-1]+Mas[i-j+1,j])
              THEN
                M[i,j,k] := M[i-1,j-1,k-1]+Mas[i-j+1,j];
            END
          ELSE
            BEGIN
              M[i,j,k] := M[i-1,j,k];
              IF (j>1) AND (M[i,j,k]<M[i-1,j-1,k])
              THEN
                M[i,j,k] := M[i-1,j-1,k];
              IF (j>1) AND (k>1) AND (M[i,j,k]<M[i-1,j-1,k-1])
              THEN
                M[i,j,k] := M[i-1,j-1,k-1];
              IF (k>1) AND (M[i,j,k]<M[i-1,j,k-1])
              THEN
                M[i,j,k] := M[i-1,j,k-1];
              M[i,j,k] := M[i,j,k]+Mas[i-j+1,j]+Mas[i-k+1,k];
            END;
        END;
  WRITELN(M[2*N-1,N,N]);
END.