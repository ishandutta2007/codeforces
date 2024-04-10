import qualified Data.ByteString.Char8 as B
import Data.Maybe
import Control.Monad

main = do
	[a,b] <- replicateM 2 $ fmap (fst . fromJust . B.readInteger) B.getLine
	putStrLn $ case (compare a b) of
		EQ -> "="
		LT -> "<"
		GT -> ">"